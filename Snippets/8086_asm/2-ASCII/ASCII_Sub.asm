TITLE   ASCII SUBTRACTION
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

        ;do AAS on my own!
        SUB AX,AX                    ;clear AX
        MOV AL,'7'                   ;'7'=37H
        SUB AL,'2'                   ;'2'=32H, 37-32=5 already
        OR  AL,00110000B             ;get its ascii

        ;AAS also works on unpacked bcd!
        MOV AX,105H                  ;AX=0105H unpacked BCD for 15
        MOV CL,06                    ;CL=0006H for 6
        SUB AL,CL                    ;15-6
        AAS                          ;AX=0009?
        
                
        MOV AH,4CH                   ;EXIT
        INT 21H                      ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
