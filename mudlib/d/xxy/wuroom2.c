// Room: /d/xxy/wuroom2 
inherit ROOM; 
 
void create ()
{
  set ("short", "会客厅");
  set ("long", @LONG
只有达到武级的高手才能进这栋楼,北面靠窗的地方有张矮几,上面摆了一
幅围棋,墙上挂着当代名家的手笔,一张檀木大桌,几乎占了小半个房间.西面是
寝室.
LONG);

  set("objects", ([ /* sizeof() == 5 */
  "/d/obj/food/mifan.c" : 1,
  "/d/obj/food/shuijiao.c" : 1,
  "/d/obj/food/guazi.c" : 1,
  "/d/obj/food/grape.c" : 1,
  "/d/obj/food/apple.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wuroom",
  "west" : __DIR__"wuroom3",
]));

  setup();
}
