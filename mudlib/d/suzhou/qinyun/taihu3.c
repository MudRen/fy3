// Room: /u/oldsix/room1/taihu3.c

inherit ROOM;

void create()
{
	set("short", "太湖");
	set("long", @LONG
菱塘尚未过完，阿碧又指引小舟从一丛芦苇和茭白中穿了过去。一眼望去，
满湖荷叶、菱叶、茭白，都是一模一样，兼之荷叶、菱叶在水面飘浮，随时一阵
风来，便即变幻百端，霎时间局面便全然不同。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
}
int init()
{
    object me;
    me=this_player();
    call_out("greeting",5,me);
}
void greeting(object me)
{
	me->move(__DIR__"taihu4.c");
}
