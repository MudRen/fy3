// Room: /d/xxy/caodi 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "草地");
  set ("long", @LONG
一片约半里宽的荒草地,脚下时常出现深深的泥沼,不小心蹋进去,就
很难出来,荒草积水,更是泥泞,每一踏足,唧唧作响,落脚稍重,污水立即
飞溅,煞是讨厌.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"caodi1",
  "south" : __DIR__"feixu",
]));
  set("outdoors", "/d/xxy");
  setup();
}
