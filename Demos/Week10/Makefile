# REV20: Thu 30 Nov 2023 07:00
# REV19: Fri 16 Sep 2022 18:00
# REV18: Wed 24 Nov 2021 08:00
# REV17: Wed 25 Mar 2020 16:00
# REV03: Thu 09 Mar 2017 21:00
# START: Tue 13 Sep 2016 11:00

CC            = gcc
CPP           = cpp
CFLAGS        = -std=gnu18
LDFLAGS       = 
CPPFLAGS      =
DEPFLAGS      = -MM -MT $(@:.d=.o) 
OUTPUT_OPTION = -o $@
COMPILE       = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
SRCS          = $(wildcard *.c)
OBJ           = $(SRCS:.c=.o)
DEP           = $(OBJ:.o=.d)
PROGS         = $(SRCS:.c=  )

P10=10-server
P11=11-client
P12=12-clisvr
P50=50-get-put
P51=51-get-put-loop
P52=52-open-close
P53=53-file-pointer
P54=54-write
P55=55-write
P56=56-copy
P57=57-dup
P58=58-dup2
P59a=59a-io
P59b=59b-io
P59c=59c-io
P60=60-readwrite
P61=61-dupdemo
P70=70-os161
P71=71-os171
P72=72-os172
P73=73-os181
P74=74-os182
P75=75-os191
P76=76-os192
P99=99-extra


EXECS= \
        $(P10)  \
        $(P11)  \
        $(P12)  \
        $(P50)  \
        $(P51)  \
        $(P52)  \
        $(P53)  \
        $(P54)  \
        $(P55)  \
        $(P56)  \
        $(P57)  \
        $(P58)  \
        $(P59a) \
        $(P59b) \
        $(P59c) \
        $(P60)  \
        $(P61)  \
        $(P70)  \
        $(P71)  \
        $(P72)  \
        $(P73)  \
        $(P74)  \
        $(P75)  \
        $(P76)  \
        $(P99)  \


DEMOFILES=\
	demo-file1.txt   \
	demo-file2.txt   \
	demo-file3.txt   \
	demo-file4.txt   \
	demo-file5.txt   \
	demo-file6.txt   \
	demo-file7.txt   \
	demo-file8.txt   \
	demo-fileA.txt   \
	demo-copy.txt    \
        $(P59a)-demo.txt \
        $(P59b)-demo.txt \
        $(P59c)-demo.txt \
        $(P61)-demo.txt  \
        $(P70)-demo.txt  \
        $(P71)-demo.txt  \
        $(P72)-demo.txt  \
        $(P73)-demo.txt  \
        $(P74)-demo3.txt \
        $(P74)-demo4.txt \
        $(P75)-demo.txt  \
        $(P76)-demo.txt  \
        $(P99)-demo.txt  \
        

MODE644=\
	demo-file4.txt \

all:  $(EXECS) demo-file4.txt

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

.phony: clean demo
clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo: demo-file4.txt
demo-file4.txt:
	@echo "Line 1: Blah Blah Blah 1" >  demo-file4.txt
	@echo "Line 2: Blah Blah Blah 2" >> demo-file4.txt
	@echo "Line 3: Blah Blah Blah 3" >> demo-file4.txt
	@chmod 644 $(MODE644)


## CC            = gcc
## CPP           = cpp
## LDFLAGS       = 
## CFLAGS        =
## CPPFLAGS      =
## DEPFLAGS      = -MM -MT $(@:.d=.o) 
## OUTPUT_OPTION = -o $@
## COMPILE       = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
## SRCS          = $(wildcard *.c)
## OBJ           = $(SRCS:.c=.o)
## DEP           = $(OBJ:.o=.d)
## PROGS         = $(SRCS:.c=  )

## 
## all: main1 main2 main3 main4
## 
## main1: main1.o sub1.o sub2.o sub3.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
##    
## main2: main2.o sub1.o sub2.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
##    
## main3: main3.o sub1.o sub3.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
##    
## main4: main4.o sub2.o sub3.o
## 	$(CC) $(OUTPUT_OPTION) $^ $(LDFLAGS)
## 
## -include $(DEP)
## 
## %.d: %.c
## 	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@
## 
## .phony: clean cleandep all
## 
## clean:
## 	rm -rf $(OBJ) $(PROGS) $(DEP) 
## 
