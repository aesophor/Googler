TITLE   UNSIGNED MULTIPLICATION
PAGE    60,132
;---------------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;---------------------------------------------
DTSEG   SEGMENT
; byte x byte
DATA1   DB 25H
DATA2   DB 65H

; word x word
DATA3   DW 2378H
DATA4   DW 2F79H

; word x byte
DATA5   DB 6BH
DATA6   DW 12C3H

RESULT  DW ?
DTSEG   ENDS
;---------------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV  AX,DTSEG
        MOV  DS,AX
;---------------------------------------------
; 1. byte x byte (AL) x (REG/MEM) -> (AX)
;        SUB  AX,AX  ;not needed !
        MOV  AL,DATA1
        MUL  DATA2
        MOV  RESULT,AX
;---------------------------------------------
; 2. word x word (AX) x (REG/MEM) -> (DX AX)
        MOV  AX,DATA3
        MUL  DATA4
        MOV  RESULT,AX
        MOV  RESULT+2,DX
;---------------------------------------------
; 3. byte x word (AL) x (REG/MEM) -> (DX AX)
        SUB  AH,AH
        MOV  AL,DATA5
        MUL  DATA6
        MOV  RESULT,AX
        MOV  RESULT+2,DX
;---------------------------------------------
<NOTE>: compare (2) and (3)
        (2D3F) word x word
        (003F) byte x word
        this is why in (3) AH has to be cleared.
;---------------------------------------------
        INT  21H                 ;interrupt
        MOV  AH,4CH              ;EXIT
        INT  21H                 ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END  MAIN
