// thd:duchuan1.c

inherit ROOM;

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
����һ�Ҷɺ��õ�ľ������Ȼ����������С���ƺ�һ��Ҳ���������
����ʵ������ʮ�ּ�̣��ٴ�ķ���Ҳ�����ɢ����С���Ĳ��а����˸�
������ˮ�����������ò��ŵ��İ�ȫ�ˡ���β��һ���������������Ŷ棬
����������Ҳ�����֡�
LONG
	);

	set("exits", ([ /* sizeof() == 0 */
]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}
