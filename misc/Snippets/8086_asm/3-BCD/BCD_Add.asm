TITLE   BCD ADDITION
PAGE    60,132
;-------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;-------------------------------------
DTSEG   SEGMENT
DATA1   DB 47H
DATA2   DB 25H
DATA3   DW 1789H
DATA4   DW 2394H 
RESULT1 DB ?
RESULT2 DW ?
DTSEG   ENDS
;-------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX
;-------------------------------------
; 1. BCD ADDITION IN THE SIZE OF BYTE
        SUB AH,AH
        MOV AL,DATA1
        ADD AL,DATA2
        ADD AL,06H
        MOV RESULT1,AL
;-------------------------------------
; 2. BCD ADDITION IN THE SIZE OF WORD
        SUB AX,AX
        MOV AX,DATA3
        ADD AX,DATA4
        ADD AL,66H
        ADD AH,06H
        MOV RESULT2,AX
;-------------------------------------
        MOV AH,4CH
        INT 21H

MAIN    ENDP
CDSEG   ENDS
        END MAIN
