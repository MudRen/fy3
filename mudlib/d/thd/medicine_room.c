// thd:medicine_room.c
// 97.7.13 by Aug

inherit ROOM;

void create()
{
      set("short", "炼丹房");
	set("long", @LONG
这里是黄岛主的炼丹房。房间的中央是座古色古香的炼丹炉，四周堆
放着各种各样的珍贵药材。因为炉火整日不熄，炼丹房里总是烟雾缭绕，
平添一种神秘气氛。一个哑仆在旁边不停的扇火。黄药师的九香玉露丸
天下闻名，你如果学会了炼制之法，也不妨到这里来试试。
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/yapu7" :  1,
	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
	    "east" : __DIR__"in_road4",
	]));
      
	set("no_fight", 1);

	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
  	if((dir!="east")||(me->query_temp("in_lian")!=1)) 
		return ::valid_leave(me, dir);

	return notify_fail(
"你的丹药还没炼好怎么能离开呢？
如果你一定要离开就得放弃(halt)炼制九花玉露丸。\n");
}

void init()
{
	add_action("do_mingsi", "mingsi");
}


int do_mingsi(string arg)
{
	if(this_player()->query_temp("in_lian")!=1) return 0;

	write(
"你正在专心炼制九花玉露丸，怎么能冥思呢？
你一定要冥思就要放弃(halt)炼制九花玉露丸。\n");		

	return 1;
}
