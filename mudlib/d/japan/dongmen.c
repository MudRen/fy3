// Room: /d/japan/dongmen
inherit ROOM;

void create()
{
  set ("short", "神户东门");
  set ("long", @LONG
这里就是神户的东门,来来往往的人还挺多,看门的兵卒来往盘查着
进出的人,喧闹声使这地方变得分外热闹.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiedaoe3",
   "east" : __DIR__"path",
]));
  set("objects",( [ /* sizeof() == 1 */
  __DIR__"npc/chengwei":3,
]));
  set("outdoors", "/d/japan");
  setup();
}
int valid_leave(object me, string dir)
{
        object ob;
        ob = present("cheng wei", this_object());
        if (  ob && dir == "east" && !wizardp(me))
              return notify_fail(ob->query("name")+"喝道:          现在不准通行,快离开此地!!\n");
        return ::valid_leave(me, dir);
}
