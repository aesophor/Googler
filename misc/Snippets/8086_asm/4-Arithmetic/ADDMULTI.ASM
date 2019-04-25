TITLE   MULTIWORD ADDITION
PAGE    60,132
;---------------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;---------------------------------------------
DTSEG   SEGMENT
DATA1   DQ 548FB9963CE7H
        ORG 8
DATA2   DQ 3FCD4FA23B8DH
        ORG 16
SUM     DQ ?
DTSEG   ENDS
;---------------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV  AX,DTSEG
        MOV  DS,AX
        CLC                      ;clear Carry Flag
        LEA  SI,DATA1            ;load pointer to DATA1
        MOV  CX,03               ;load loop counter
        AND  AX,0H               ;clear AX. AX will hold the sum
ADDMW:  MOV  AX,[SI]             ;load 4 bytes from DATA1 into AX
        ADD  AX,8[SI]            ;add 4 bytes from DATA2 into AX
        
        ;ADC  DX,00               ;store carry in a register
        ;ADD  16[SI]+2,DX

        ;----check previous round----
        MOV  DX,[SI]-2
        ADD  DX,8[SI]-2
        ADC  AX,00

        ADD  16[SI],AX           ;store sum
        ADD  SI,2                ;point to next word
        LOOP ADDMW               ;loop until finished
        MOV  AH,4CH              ;EXIT
        INT  21H                 ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END  MAIN
