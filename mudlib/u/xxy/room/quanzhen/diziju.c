// diziju.c ���Ӿ�


inherit ROOM;
int do_pull(string arg);

void create()
{
	set("short", "���Ӿ�");
	set("long", @LONG
	������ȫ��̵��Ӿ�ס�ķ��䡣����ܴ����������һ��һ
�ŵĴ������ϱ��춼�۵����������룬����һ���˶�û�У�Ҳ�����е�
���Ӷ�ȥ����ȥ�ˡ���ǽ�ĵط���һ������(cabinet)��
LONG
	);

	set("sleep_room",1);

	set("exits", ([
		"north" : __DIR__"jingxiushi",
	]));

	set("item_desc", ([
        "cabinet": "һ�����ӣ�Ҳ���Ƕѷ������õġ�\n"
	]) );

	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_pull","pull");
}

int do_pull(string arg)
{
	object me=this_player();

	if( !arg || arg != "cabinet" ) {
		return notify_fail("��Ҫ����ʲô��\n");
	}

	message_vision("$Nʹ���ѹ����������ֳ�һ�����ڡ�ԭ�����������ҵ���ڡ�\n", this_player());
       	set("exits/down", __DIR__"mishi");
	remove_call_out("close");
	call_out("close", 8, this_object());		

	return 1;
}

void close(object room)
{
	message("vision","������֨֨�ػص�ԭ�أ�����ڵ�ס�ˡ�\n", room);
	room->delete("exits/down");
}	