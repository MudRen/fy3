// Room: /d/huashan/qingke.c

inherit ROOM;

void create()
{
	set("short", "青柯坪");
	set("long", @LONG
走过崎岖的十八盘，穿过云门，就到了青柯坪。青柯坪是一山间盆地
，地势略为平坦。从这里开始，上山的路都是由原地凿出的石阶。远远望
见一个小小石亭，便是赌棋亭了。相传宋太祖与华夷先生曾弈棋于此，将
华山作为赌注，宋太祖输了，从此华山上的土地就不须缴纳钱粮。
LONG
	);
	set("outdoors", "xx");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"shaluo",
  "eastup" : __DIR__"huixinshi",
]));

	setup();
	replace_program(ROOM);
}
