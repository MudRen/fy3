// Room: /d/kaifeng/yangfu.c

inherit ROOM;

void create()
{
	set("short", "天波扬府");
	set("long", @LONG
天波扬府是抗辽名将杨业的府邸,自从扬业去世之后，府中只剩下
一些女子居住。门前的绿柳槐树旁，两块大石光滑异常，乃是当朝所赐.
文官过者下桥，武官过者下马。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road3",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
