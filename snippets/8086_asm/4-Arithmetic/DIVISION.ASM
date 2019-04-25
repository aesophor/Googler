TITLE   UNSIGNED DIVISION
PAGE    60,132
;---------------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;---------------------------------------------
DTSEG   SEGMENT
; byte / byte
DATA1   DB 95
DATA2   DB 10

; word / word
DATA3   DW 10050
DATA4   DW 100

; word / byte
DATA5   DW 2055
DATA6   DW 100

; doubleword / word
DATA7   DD 105432
DATA8   DW 10000

QUOTB   DB ?    ;quotion which is one byte in size.
REMAINB DB ?    ;remainder which is one byte in size.
QUOTW   DW ?    ;quotion which is one word in size.
REMAINW DW ?    ;remainder which is one word in size.
DTSEG   ENDS
;---------------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV  AX,DTSEG
        MOV  DS,AX
;---------------------------------------------
; 1. byte / byte   (AL) / (REG/MEM) -> (AL)...(AH)
        XOR  AH,AH       ;same as SUB AH,AH!
        MOV  AL,DATA1
        DIV  DATA2
        MOV  QUOTB,AL
        MOV  REMAINB,AH
;---------------------------------------------
; 2. word / word   (AX) / (REG/MEM) -> (AX)...(AH)
        ;SUB  DX,DX
        ;AND  DX,00H
        XOR  DX,DX
        MOV  AX,DATA3
        DIV  DATA4
        MOV  QUOTW,AX
        MOV  REMAINW,DX
;---------------------------------------------
; 3. word / byte   (AX) / (REG/MEM) -> (AL)...(AH)
        MOV  AX,DATA5
        DIV  DATA6
        MOV  QUOTB,AL
        MOV  REMAINB,AH
;---------------------------------------------
; 4. doubleword / word   (DX+AX) / (REG/MEM) -> (AX)...(DX)
        LEA  SI,DATA7
        MOV  AX,WORD PTR [SI]
        MOV  DX,WORD PTR [SI]+2 ;+2 to point to next word!
        DIV  DATA8
        MOV  QUOTW,AX
        MOV  REMAINW,DX
; ONE BYTE: FF
; ONE WORD: FF FF
; ONE DOUBLEWORD: FF FF FF FF
;---------------------------------------------
        INT  21H                 ;interrupt
        MOV  AH,4CH              ;EXIT
        INT  21H                 ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END  MAIN
