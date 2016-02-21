
//Mr.music  yangzhou's 青竹林

inherit ROOM;

void create()
{
        set("short", "青竹林");
        set("long", @LONG
	你走进了一片青竹林，青竹茂密修长，参差掩映，别是一番情趣，
竹径弯弯向南通向一座小楼，那就是板桥先生的书房--竹叶香斋，板桥先
生平日多在此会会文朋墨友，偶然也在此挥毫泼墨。向东是山庄大门。

LONG
        );

        set("exits", ([
                "east" : __DIR__"yanchi",
                "south" : __DIR__"xiangzhai",
        ]));

        set("item_desc", ([
                       "小楼" : "这里是板桥先生的书房--“竹叶香斋”\n" , 
                          ]));
        
        set("objects", ([
               __DIR__"npc/obj/zhuye": 2,
        ]));

        setup();
}





