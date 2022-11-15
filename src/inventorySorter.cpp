/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>
#include <llapi/EventAPI.h>
#include <llapi/DynamicCommandAPI.h>

//#include <unordered_set>

#include "version.h"
#include "itemsQueue.h"

// We recommend using the global logger.
extern Logger logger;

/*std::unordered_set<string> containerNames{
	"minecraft:barrel",
	"minecraft:shulker_box",
	"minecraft:undyed_shulker_box",
	"minecraft:trapped_chest",
	"minecraft:chest",
	"minecraft:ender_chest"
};*/

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
void PluginInit()
{
    // Your code here
    Logger logger(PLUGIN_NAME);
    logger.info("           ___          ___          ___          ___          ___          ___");
    logger.info("          /\\__\\        /\\__\\        /\\  \\        /\\  \\        /\\  \\        /\\__\\");
    logger.info("&6=========&r/:/  /&6=======&r/::L_L_&6=======&r\\:\\  \\&6======&r/::\\  \\&6======&r/::\\  \\&6======&r/:/__/_&6=============");
    logger.info(" &6\\\\&r     /:/__/       /:/L:\\__\\      /::\\__\\    /::\\:\\__\\    /:/\\:\\__\\    /::\\/\\__\\           &6\\\\");
    logger.info("  &6\\\\&r    \\:\\  \\       \\/_/:/  /     /:/\\/__/    \\:\\:\\/__/    \\:\\ \\/__/    \\/\\::/  /       ___  &6\\\\");
    logger.info("   &6\\\\&r    \\:\\__\\        /:/  /      \\/__/        \\:\\/__/      \\:\\__\\        /:/  /       /\\__\\  &6\\\\");
    logger.info("    &6\\\\&r    \\/__/        \\/__/         &6________&r    \\/__/        \\/__/        \\/__/        \\/__/   &6\\\\");
    logger.info("     &6\\\\                             /liuming7\\                                                   \\\\");
    logger.info("      &6==============================================================================================");
    logger.info("InventorySorter is made by liuming7, and Powered by LiteLoaderBDS");

    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent& event){
        using ParamType = DynamicCommand::ParameterType;
        using Param = DynamicCommand::ParameterData;
        DynamicCommand::setup(
        "sort", // The command
        "sort your inventory", // The description
        {
            
        }, // The enumeration
        {
            
        }, // The parameters
        {
            // overloads{ (type == Enum ? enumOptions : name) ...}
            {}, 
        }, // The overloads
        [](
            DynamicCommand const& command,
            CommandOrigin const& origin,
            CommandOutput& output,
            std::unordered_map<std::string, DynamicCommand::Result>& results
        ) {}, // The callback function
        CommandPermissionLevel::Any // The permission level
        );
        return true;
    });

    Event::PlayerOpenContainerEvent::subscribe([](const Event::PlayerOpenContainerEvent& event) {
        /*Container* player_container = &(event.mPlayer->getInventory());
        ItemsQueue playerItemsQueue(player_container,9);
        playerItemsQueue.sort();*/

        if (event.mContainer==nullptr || event.mContainer->getTypeName()!="CONTAINER"){
            return true;
        }
        Container* block_container = event.mContainer;
        ItemsQueue blockItemsQueue(block_container);
        blockItemsQueue.sort();
        return true;
    });

    Event::PlayerCmdEvent::subscribe([](const Event::PlayerCmdEvent& event){
        if(event.mCommand=="sort"){
            Container* player_container = &(event.mPlayer->getInventory());
            ItemsQueue itemsQueue(player_container,9);
            itemsQueue.sort();
        }
        return true;
    });
/*
    Event::PlayerOpenInventoryEvent::subscribe([](const Event::PlayerOpenInventoryEvent& event) {
        Container* player_container = &(event.mPlayer->getInventory());
        ItemsQueue itemsQueue(player_container,9);
        itemsQueue.sort();
        return true;
    });*/
}

/*
    using ParamType = DynamicCommand::ParameterType;
    using Param = DynamicCommand::ParameterData;
    DynamicCommand::setup(
    "sort", // The command
    "sort your inventory", // The description
    {
        {"enum_1", {"add", "remove"}},
        {"enum_2", {"list"}},
    }, // The enumeration
    {
        Param("testEnum", ParamType::Enum, false, "enum_1"),
        Param("testEnum", ParamType::Enum, false, "enum_2"),
        Param("testInt", ParamType::Int, true),
    }, // The parameters
    {
        // overloads{ (type == Enum ? enumOptions : name) ...}
        {"enum_1", "testInt"}, // example_command <add|remove> [testInt]
        {"enum_2"}, // example_command <list>
    }, // The overloads
    [](
        DynamicCommand const& command,
        CommandOrigin const& origin,
        CommandOutput& output,
        std::unordered_map<std::string, DynamicCommand::Result>& results
    ) {
        auto& action = results["testEnum"].get<std::string>();
        switch (do_hash(action.c_str()))
        {
        case do_hash("add"):
            if (results["testInt"].isSet)
            output.success(fmt::format("add {}", results["testInt"].getRaw<int>()));
            else
            output.success("add nothing");
            break;
        case do_hash("remove"):
            if (results["testInt"].isSet)
            output.success(fmt::format("remove {}", results["testInt"].getRaw<int>()));
            else
            output.success("remove nothing");
            break;
        case do_hash("list"):
            output.success("list");
            break;
        default:
            break;
        }
    }, // The callback function
    CommandPermissionLevel::GameMasters // The permission level
    );*/