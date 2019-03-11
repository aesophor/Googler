TITLE   BCD SUBTRACTION
PAGE    60,132
;-------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;-------------------------------------
DTSEG   SEGMENT
DATA1   DB 45H
DATA2   DB 27H
DATA3   DW 2359H
DATA4   DW 1794H 
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
; 1. BCD SUBTRACTION IN THE SIZE OF BYTE
        SUB AH,AH
        MOV AL,DATA1
        SUB AL,DATA2
        SUB AL,06H      ;correction
        MOV RESULT1,AL
;-------------------------------------
; 2. BCD SUBTRACTION IN THE SIZE OF WORD
        SUB AX,AX
        MOV AX,DATA3
        SUB AX,DATA4
        SUB AX,0660H     ;correction
        MOV RESULT2,AX
;-------------------------------------
        MOV AH,4CH
        INT 21H

MAIN    ENDP
CDSEG   ENDS
        END MAIN
