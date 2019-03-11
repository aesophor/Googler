TITLE   ASCII ADDITION
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

        ;do AAA on my own!
        SUB AX,AX                    ;clear AX
        MOV AL,'5'                   ;'5'=35H
        ADD AL,'3'                   ;'3'=33H
        AND AL,00001111B             ;68H --> 08H
        OR  AL,00110000B             ;get its ASCII

        ;this time try out AAA!
        XOR AX,AX                    ;clear AX
        MOV AL,'6'                   ;'6'=36H
        ADD AL,'2'                   ;'2'=32H
        AAA                          ;38H --> 08H
        OR  AL,00110000B             ;get its ASCII

        ;AAA also works on unpacked BCD!
        AND AX,00H                   ;clear AX
        MOV AX,0108H                 ;AX=0108H unpacked BCD for 18
        MOV CL,0009H                 ;CL=0009H for 9
        ADD AL,CL                    ;18+9
        AAA                          ;AX=0207?
                
        MOV AH,4CH                   ;EXIT
        INT 21H                      ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
