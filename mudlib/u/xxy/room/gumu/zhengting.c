// zhengting.c ����
// By Lgg,1998.9

#include <ansi.h>
inherit ROOM;

int do_sleep(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
	�����ǹ�Ĺ������������Ӧ��ͣ�����ѹ�ľ֮��Ķ�����ȴ��֪
�����˰㵽����ȥ�ˡ������ж�����һλ������Ů�������ϰڷ���һ��ʯ
ͷ���ɵĴ�(chuang)�����к�ϵ��һ�����ӣ���֪����ʲô�õģ�����
֮�⣬���ް��衣
LONG
	);

	set("exits", ([
		"west" : __DIR__"liangong",
		"north" : __DIR__"xiaoting",
		"south" : __DIR__"houting",
	]));

	set("objects", ([ 
		__DIR__"npc/longnv" : 1,
	]));
	set("valid_startroom",1);

	set("item_desc", ([
        "chuang": "����һ����"+HIB"ǧ�꺮��"NOR+"��ɵĺ��񴲡�\n"
	]) );

	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object me=this_player();
	int lvl_force;

	if( !arg || arg == "" ) {
		return notify_fail("��Ҫ˯���Ķ���\n");
	}

	lvl_force=(int)me->query_skill("force",1);
	if(lvl_force>150) //force ���� 150
		{
		message_vision("$N�����˺��񴲣���ʼǱ���ڹ���ʹ��Ϣ���д�С���졣\n",this_player());
		if (random(20)>12) {
			message_vision("$N��Ϣ��ϣ�ֻ���þ���������Ϣ���������ڶ�����\n", this_player());
			me->improve_skill("force", random(lvl_force));
			me->receive_damage("qi",random(lvl_force/3));
		}
		else 
			message_vision("$N��Ϣ��ϣ�վ������������������������ûʲô������\n", this_player());	
		}
	else
		message_vision("$N���Ϻ��񴲣�ֻ���ñ���̹ǣ���������һ���Ǳ�����������������\n", this_player());	
	return 1;
}