// Room: /d/gaibang/wdandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);

	set("exits", ([
			"southwest" : __DIR__"underqz",
			"northeast" : __DIR__"qzandao1",
	]));

	set("objects",([
		"/d/city/obj/jitui" : 3,
		"/d/city/obj/jiudai" : 1,
	]));

	setup();
	replace_program(ROOM);
}


