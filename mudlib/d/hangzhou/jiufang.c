// Room: /d/hangzhou/jiufang.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "酒坊");
	set("long", @LONG
一进门,便见到许多酒坛摆在屋子的四周,中间是一口巨大密封的
磁缸.旁边的一口大锅里面不知在炒些什么,一股浓重的就香扑鼻而来
这里酿造的曲酒闻名天下,乃是一所官坊.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dadao1.c",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chenlaoqu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
