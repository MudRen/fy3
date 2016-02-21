// thd:hill9.c

inherit ROOM;

void create()
{
      set("short", "山路");
	set("long", @LONG
从这里上去就是弹指峰的山顶了。山路两旁一草一石，一花一木虽都
平常，确处处显现出一派自然风光，决不是俗世中的花红柳绿、残花败叶
所能比拟的。在这里连残叶都能成为一道风景。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "northup" : __DIR__"peak",
          "southdown" : __DIR__"yun_jian",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

