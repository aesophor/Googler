TITLE   OUTPUT A SINGLE CHAR TO MONITOR
PAGE    60,132
;-----------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;-----------------------------------------
DTSEG   SEGMENT
DTSEG   ENDS
;-----------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX
        
        MOV AH,02H      ;select string output
        MOV DL,'J'      ;load the character to DL
        INT 21H         ;invoke the interrupt
        
        MOV AH,4CH      ;EXIT
        INT 21H         ;invoke the interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
