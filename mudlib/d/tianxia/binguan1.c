// Room: /d/new/tianxia/binguan1
inherit ROOM;

void create()
{
  set ("short", "宾馆大厅");
  set ("long", @LONG
大厅中空落落的摆了两张紫檀椅子,一副巨大的猛虎下山图占了整一
面墙壁.角落中的高架上几盆花草绿得诱人.向北有两扇大门.
LONG);
set("exits",([

 "north" : __DIR__"binguan",
]));
  setup();
}
