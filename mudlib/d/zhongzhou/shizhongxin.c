// Room: /d/zhongzhou/shizhongxin.c

inherit ROOM;

void create()
{
	set("short", "市中心");
	set("long", @LONG
这是中州的市中心，两条街道在这里划个大十字。整个中州就数着两
条街道最热闹了。其间三教九流，行行色色的人来来往往。南北一条宽敞
的街道，一看就是刚刚修建好不久，一块路牌清楚的写着"文定街".东西
那条街道要陈旧一点，一块路牌上的字已看不太清，依稀刻着“延陵路”
三个字。
LONG
	);
	set("outdoors", "/d/zhongzhou");
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yanlingdong",
  "south" : __DIR__"wendingnan1",
  "west" : __DIR__"yanling",
  "north" : __DIR__"wendingbei1",
]));
	set("no_sleep_room", 1);
	set("no_fight", 1);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/hfh.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
        "/obj/board/renwu_board"->foo();
}
