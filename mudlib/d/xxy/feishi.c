// Room: /d/xxy/feishi 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "废旧寺庙");
  set ("long", @LONG
走过草地,沿着红墙东转,眼前是一座颓废的古寺.山门虚掩,一溜长
慢草的石阶伸向山门.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"dadian",
  "west" : __DIR__"caodi2",
]));
  set("outdoors", "/d/xxy");
  setup();
}
