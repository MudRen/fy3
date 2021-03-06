
//d/zhongzhou/biwuchang.c
inherit ROOM;
string look_shelf();

void create()
{
         set("short", "比武台");
        set("long", @LONG
这是一个四丈见方的擂台。粗壮结实的木柱撑起一片平台，四角的支柱上
高挂着四副对联，四面的观众都能清楚地看到台上的手起脚落。擂台角上有个
兵器架，刀剑鞭棒样样俱全。
LONG );
        set("outdoors", "zhouzhou");
         set("biwuchang", 1);
        set("item_desc", ([
                "shelf" : (: look_shelf :),
        ]));

        set("exits", ([
                "down"        : __DIR__"biwuchangyuan.c",
        ]));
        set("objects", ([
                __DIR__"npc/caipan.c": 1,
        ]));
        set("no_clean_up", 0);
        set("no_openshelf", 1);
        setup();
}

void init()
{
        add_action("do_war",({"fight","hit","kill","qiecuo"}));
        add_action("do_quit",({"du","dazuo","exercise","lian","learn","xue",
                    "practice","study","exit","quit","halt"}));
        add_action("do_take","take");
        add_action("do_open","open");
        add_action("do_close","close");
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("裁判席只有被特邀才能进去。\n");
         if( dir=="down" && (me->query_temp("war_biwu")||me->query_temp("war_ask") ))
                 return notify_fail("\n");
        me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}
int do_war(string arg)
{
        write(this_player()->query("name")+"，在比武场只能用指令 biwu 来切磋！\n");
         return 1;
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"，专心比武吧！\n");
        return 1;
}



