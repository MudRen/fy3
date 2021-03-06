// Room: /d/jinling/huayuan.c

inherit ROOM;

void create()
{
	set("short", "紫云花园");
	set("long", @LONG
忽然你眼前一紫，只见一座小楼“浮”于一片紫色的云采上。定睛一看，
原来小楼四周种满了淡紫色的花朵(flower)，微风吹过就象飘动的云彩。紫云楼
果然名不虚传。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaolu.c",
  "west" : __DIR__"ziyunlou.c",
]));
	set("outdoors", "/d/jingling");
	set("no_magic", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : "这是来自大理国的名种茶花，名叫“紫气东来”。当旭日照在其上时，

会产生蒙蒙紫色毫光，应此得名。",
]));
	set("light_up", 1);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
