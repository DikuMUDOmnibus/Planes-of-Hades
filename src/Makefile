CC      = gcc
PROF    =
NOCRYPT = 
C_FLAGS = -ggdb -g3 -Wall  $(PROF) $(NOCRYPT) $(DBUGFLG)
L_FLAGS = -lcrypt

O_FILES = act_comm.o act_info.o act_move.o act_obj.o act_wiz.o comm.o const.o \
	     db.o handler.o interp.o magic.o save.o special.o fight.o \
        kav_info.o kav_fight.o kav_wiz.o clan.o  mage.o rot_wiz.o \
        drow.o wizutil.o arena.o vamp.o vampie.o \
        rotain.o update.o monk.o darkheart.o daemon.o board.o \
	   bit.o mem.o olc.o olc_act.o olc_save.o string.o build.o \
     	kingdom.o demon.o monk2.o garou.o vamp3.o ninja.o \
        class_sav.o monk3.o monk4.o 


low: $(O_FILES)
	rm -f low
	$(CC) $(L_FLAGS) -o low $(O_FILES)
	chmod g+w low
	chmod g+w $(O_FILES)

.c.o: merc.h
	$(CC) -c $(C_FLAGS) $<
