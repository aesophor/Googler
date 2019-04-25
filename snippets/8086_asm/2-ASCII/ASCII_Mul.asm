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
        MOV AL,'7'                   ;AL=37H
        AND AL,0FH                   ;AL=07H
        MOV DL,'6'                   ;DL=36H
        AND DL,0FH                   ;DL=06H
        MUL DL                       ;AX=ALxDL
        AAM                          ;ascii adjust for multiplication
        OR  AH,00110000B
        OR  AL,00110000B
        
                
        MOV AH,4CH                   ;EXIT
        INT 21H                      ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
