// thd:green_pavilion.c
// 97.7.14 bu Aug

inherit ROOM;

void create()
{
      set("short", "积翠亭");
	set("long", @LONG
这是座完全用竹子搭成的亭子。整个亭子已经和竹林融为一体，从远
处看，根本分不出哪里是竹林，哪里是积翠亭。亭上悬着块匾，上书“积
翠亭”三字，这当然也是黄岛主的手迹，但这里的字体确十分特别，那不
象是字，到象是一幅竹叶图，它所有的笔画都是由竹叶组成的，看来别有
一番风味。黄岛主常在这里把酒吟诗，思索哲理，其洒脱飘逸比之竹林七
杰当也毫不逊色。亭子的北边是绿竹林的出口，而南边的竹林特别浓密，
你怎么也辨认不出道路了。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 5 */
          "north" : __DIR__"np",     
          "west" : __DIR__"wp",          
          "east" : __DIR__"ep",               
          "northwest" : __DIR__"nwp",
          "northeast" : __DIR__"nep",
	]));
      
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_go", "go");	
}

int do_go(string arg)
{
	object me;

	me=this_player();
	switch(arg)
	{
		case "south": { me->move(__DIR__"sp"); return 1; }
		case "s": { me->move(__DIR__"sp"); return 1; }
		case "southwest": { me->move(__DIR__"swp"); return 1; }
		case "sw": { me->move(__DIR__"swp"); return 1; }
		case "southeast": { me->move(__DIR__"sep"); return 1; }
		case "se": { me->move(__DIR__"sep"); return 1; }	
		default: return 0;
	}
}