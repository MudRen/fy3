#include <room.h>
inherit ROOM;

void create()
{
      set("short","月亮门");
      set("long",@LONG
这里是一个月亮门，两边是红色的山庄围墙，门的那边就是
山庄的后山，那是禁地，外人没有庄主的邀请是不准进来的
就是本门弟子也是这样，
LONG);
      set("outdoors", "xx");
      set("exits",([ /* sizeof() == 2 */
          "east" : __DIR__"path2",
          "south" : __DIR__"weiqiang",
          "north": __DIR__"weiqiang2",
      ]));
      set("objects", ([
            "/d/yandang/npc/dizi" : 4,
        ]));

      setup();
}

