inherit ROOM;
void create()
{
        set("short", "闺房");
        set("long", @LONG
    这是杨不悔小姐的闺房，一股幽香扑面而来。一张绣榻放在墙角，垂着细纱。
四面墙壁上挂了好些刀剑。
LONG
        );

        set("exits", ([
                "south" : __DIR__"huayuan",
                ]));

        setup();
        replace_program(ROOM);
}
