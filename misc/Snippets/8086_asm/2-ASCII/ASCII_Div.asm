TITLE   ASCII MULTIPLICATION
PAGE    60,132
;-----------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;-----------------------------------
DTSEG   SEGMENT
DTSEG   ENDS
;-----------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX

        SUB AX,AX                    ;clear AX
        MOV AX,3435H                 ;'45' as the numerator
        AND AX,0F0FH                 ;AX=0405H
        AAD                          ;AX=002DH
        MOV CL,08H                   ;'8' as the denominator
        DIV CL                       ;45/8=5...5
        OR  AX,3030H                 ;convert both Q and R to their ASCII form     
                
        MOV AH,4CH                   ;EXIT
        INT 21H                      ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
