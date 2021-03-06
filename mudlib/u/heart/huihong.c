// Room: /u/uuui/huihong.c

inherit ROOM;

void create()
{
        set("short", "恢弘殿");
        set("long", @LONG
和影壁相对的是一座大殿，匾额‘中写着“恢弘殿”
三个字大殿雕梁画柱。殿内四个圆柱，八盏宫灯。与红色
的幔帐相衬显得既协调又凝至。地砖被打磨的光亮鉴人。
两边供奉着王府列祖列宗和凝王府立过战功将军的牌位。
正中案上供着一个金架，但上面空空如也。据说架上曾放
这本朝开国皇帝御赐的免死金牌。此殿每日有专人添香打
扫。故而香烟缭绕，终年不断。一般政务活动都在东面的
议事厅。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"guandao2",
  "east" : __DIR__"yishiting",
  "north" : __DIR__"huatuo",
  "south" : __DIR__"yingbi",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

