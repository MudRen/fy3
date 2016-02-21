// Room: /u/uuui/huayuan.c

inherit ROOM;

void create()
{
        set("short", "小花园");
        set("long", @LONG
这就是凝王府的皇家花园，花园约占地两亩，亭台
楼榭无不精巧。远远的望去能看见一个八角连体亭，显
得特点与众不同。一塘流水给花园增添明秀的色彩，流
水顺着假山想北面流去。让整个花园都有了动态。但花
园四周有一轮围墙。给人一种幽静的感觉。花园的西北
角有个月牙小门。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"guandao",
  "northwest" : __DIR__"tingzi",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

