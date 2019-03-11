TITLE   ADDING 5 BYTES
PAGE    60,132
;P.84:  Write a program to calculate the total sum
;       of 5 bytes of data. Each byte represents
;       the daily wages of a worker. This person
;       does not make more than $255 (FFH) a day.
;       The decimal data is as follow:
;       125, 235, 197, 91, and 48.
;
;       <NOTE>:ADC is the same as ADD
;              but add an extra 1
;              if the carry flag is set.
;------------------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;------------------------------------------------
DTSEG   SEGMENT
WAGES   DB 125,235,197,91,48
        ORG 8
SUM     DW ?
DTSEG   ENDS
;------------------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX               ;load DTSEG address into DS
        MOV SI,OFFSET WAGES     ;load pointer to WAGES data
        MOV AX,0                ;AX will be used to hold sum
        MOV CX,5                ;load loop counter
ADDWG:  ADD AL,BYTE PTR [SI]    ;add content of SI into AX
                                ;<NOTE>: add only ONE byte!
        ADC AH,00               ;if d7-d8 carry --> add it to AH
        INC SI                  ;point to next data
        DEC CX                  ;decrement loop counter
        JNZ ADDWG               ;continue if not done
        MOV SUM,AX              ;store the result
        MOV AH,4CH              ;EXIT
        INT 21H                 ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
