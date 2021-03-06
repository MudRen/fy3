// Room: /d/huanggon/tiananmen.c

inherit ROOM;

void create()
{
	set("short", "天安门");
	set("long", @LONG
天安门是皇城的正门,高高的城楼下是五道大门,每逢大典,就有诏
书摆在'龙亭'中,抬到此地,由礼部官员在城楼上大声宣告庆典的消息,
天安门北面是午门,南边是片广场.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/duolong.c" : 1,
  __DIR__"npc/huanggonshiwei.c" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wumen",
  "south" : __DIR__"guangchang",
]));
	set("outdoors", "/d/huanggon");
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object ob,string dir)
{
  if (ob->query("gender")!="中性"&&!ob->query_temp("huanggon/enter")) {
if (dir=="north"&&ob->query("xxy/lvl")<4)  {
   if (present("shi wei",this_object())) {
     message_vision("皇宫侍卫拦住$N:大胆,敢擅闯皇宫么?\n",ob);
     return notify_fail("");
   }
   if (present("duo long",this_object())) {
     message_vision("多隆拦住$N:皇宫也是随便可以进的么?\n",ob);
     return notify_fail("");
   }
  }
 }
return ::valid_leave(ob,dir);
}  	
