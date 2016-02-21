// Room: /d/kaifeng/shanlu1
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG
此条山路直通嵩山，由此前住嵩山进香、游玩的客人络绎不绝。
LONG);

  set("outdoors", "/d/kaifeng");
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"jiaowai",
  "westdown" : __DIR__"shanlu2",
]));

  setup();
}
