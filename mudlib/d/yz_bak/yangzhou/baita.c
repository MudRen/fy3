
//Mr.music  yangzhou's 白塔晴云

inherit ROOM;

void create()
{
        set("short", "白塔晴云");
        set("long", @LONG
	"名园依绿水，仙塔俪云庄”
        白塔的来历有一个传说：扬州盐业鼎盛时期，扬州盐运史在京曾向皇上
夸口说扬州也有和北京一样的白塔，皇上性起，立刻摆架南巡。扬州为搪塞欺君
之罪，用盐赶造了此塔，和北京遥遥相望。据说至今塔下的泥土都有咸味。

LONG
        );

        set("exits", ([
                "up"     : __DIR__"baita2",
                "east"   : __DIR__"siqiaoyanyu",
        ]));

        set("item_desc", ([
                       "瘦西湖" : "就是瘦了一点的西湖。湖上漂着一叶小舟\n" , 
                          ]));
        
        set("objects", ([
//                __DIR__"npc/zhengbanqiao": 1,
        ]));

        setup();
}





