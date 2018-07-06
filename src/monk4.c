#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merc.h"
#include "player.h"
#include "monk.h"
  /* for some reason it wasn't working with the other monk files Aron */
  void do_monkeq( CHAR_DATA *ch, char *argument )
{
    OBJ_INDEX_DATA *pObjIndex;
    OBJ_DATA *obj;
    char arg[MAX_INPUT_LENGTH];
    int vnum = 0;

    argument = one_argument( argument, arg );

    if (IS_NPC(ch)) return;

    if (!IS_CLASS(ch, CLASS_MONK))
    {
	    send_to_char("Huh?\n\r",ch);
	    return;
    }

    if (arg[0] == '\0')
    {
    send_to_char("What piece of monk armor do you wish to create?.\n\r", ch);
    send_to_char("A Belt, Visor, Plate, Ring, Leggings, Sleeves, Boots, Cape \n\r",ch);
    send_to_char("Collar, Gloves, Helmet, Ratan, Cloak or Bracer ",ch);
    return;
    }


    if      (!str_cmp(arg,"belt"     )) vnum = 123;
    else if (!str_cmp(arg,"visor"   )) vnum = 12342;
    else if (!str_cmp(arg,"cape"    )) vnum = 321;
    else if (!str_cmp(arg,"plate"   )) vnum = 14325;
    else if (!str_cmp(arg,"ring"    )) vnum = 2134;
    else if (!str_cmp(arg,"leggings" )) vnum = 2512;
    else if (!str_cmp(arg,"sleeves" )) vnum = 3214;
    else if (!str_cmp(arg,"boots"   )) vnum = 12345;
    else if (!str_cmp(arg,"collar"  )) vnum = 13441;
    else if (!str_cmp(arg,"gloves"  )) vnum = 29708;
    else if (!str_cmp(arg,"helmet"  )) vnum = 13241;
    else if (!str_cmp(arg,"ratan"   )) vnum = 12342;
    else if (!str_cmp(arg,"bracer"  )) vnum = 29706;
    else if (!str_cmp(arg,"cloak"   )) vnum = 29707;
    else
    {
    send_to_char("What piece of monk armor do you wish to create?.\n\r", ch);
    send_to_char("A Belt, Visor, Plate, Ring, Leggings, Sleeves, Boots, Cape \n\r",ch);
    send_to_char("Collar, Gloves, Helmet, Ratan, Cloak or Bracer ",ch);
    return;
    }
    if (ch->practice < 60)
    {
	send_to_char("It costs 60 primal to create a piece of monk armor\n\r",ch);
	return;
    }

    if ( vnum == 0 || (pObjIndex = get_obj_index( vnum )) == NULL)
    {
	send_to_char("Missing object, please inform Aronacus.\n\r",ch);
	return;
    }
    ch->practice -= 60;
    obj = create_object(pObjIndex, 50);
    obj_to_char(obj, ch);
    act("$p appears in a flash of white light.",ch,obj,NULL,TO_CHAR);
    act("$p appears in a flash of white light.",ch,obj,NULL,TO_ROOM);
    return;
}


