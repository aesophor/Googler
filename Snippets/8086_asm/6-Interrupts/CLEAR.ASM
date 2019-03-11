TITLE   TITLE HERE
PAGE    60,132
;------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;------------------------------------
DTSEG   SEGMENT
DTSEG   ENDS
;------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX

        MOV AX,0624H
        MOV BH,07
        MOV CX,0000
        MOV DX,184FH
        INT 10H

        MOV AH,4CH      
        INT 21H
MAIN    ENDP
CDSEG   ENDS
        END MAIN
