// Room: /d/huanggon/wanchuntin
inherit ROOM;

void create()
{
  set ("short", "万春亭");
  set ("long", @LONG
万春亭座落于一片青翠竹林之中,由高手匠人直接用翠竹弯曲搭建
而成,而竹子依然存活,其茂密的竹叶天然形成亭子的顶盖.此地向西,
是钦安殿.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qingandian",
]));
  set("outdoors", "/d/huanggon");
  setup();
  replace_program(ROOM);
}
