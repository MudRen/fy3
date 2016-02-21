//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
    这里是一条青石大道，青石缝中长满了绿油油的青草，道
路两旁整整齐齐的栽着几棵粗壮的柳树。道路上时常有些江湖
人士来来去去，有时还有装有很多箱子的大车经过。从这里往
南便是成都。西北的山路直通黑目崖。
LONG
        );

        set("exits", ([
		"northwest":__DIR__"sl1",
                "south" : __DIR__"dadao6",
        ]));
	set("objects",([
		"/npc/man6":1,
	]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


