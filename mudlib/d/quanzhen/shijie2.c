// shijie2.c ʯ��


inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ���
��ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ���
�Կ���ȫ��������۵��ܽ��ˡ�
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"shijie3",
		"southdown" : __DIR__"shijie1",
	]));

set("objects",([
__DIR__"npc/youke" : 1,
__DIR__"npc/xiangke" : 2,
]));

set("outdoors","/d/quanzhen");
	setup();
	replace_program(ROOM);
}