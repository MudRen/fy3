// Room: /u/o/oldsix/room/bigdoor.c

inherit ROOM;

void create()
{
	set("short","苏州府");
	set("long", @LONG
一道威武雄装的大门赫然出现在你的面前，张牙舞爪的石狮立在门的两旁。
门上镶着几排金光闪闪的大铜钉。抬头望去，门顶的横匾上三个醒目的大字“苏
州府”。高高的台阶通向阴森森的门内，耳边还不时转来惨叫声。
LONG
	);
        set("exits", ([ /* sizeof() == 1 */
	"west" :__DIR__"chengdongjie2",
	"east" :__DIR__"ermen",
]));
	set("objects",([
		__DIR__"npc/yayi" :2,
]));
	set("outdoors","room");
	set("no_clean_up",0);
	setup();
}
int valid_leave(object me, string dir)
{
	object yayi;
	yayi=present("yayi");
	if(!userp(me))	{
		if (dir=="east")	return 0;
			else return 1;
	}
	if(!yayi)	return 1;
	if(me->query_temp("oldsix_flag/enter")==1)	{
		me->set_temp("oldsix_flag/enter",0);
		return 1;
	}
	if(dir!="east")	return 1;
	notify_fail("衙役大声喝到：闲杂人等，禁止入内！！\n");
	return 0;
}
