/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>
#include <llapi/EventAPI.h>

#include "version.h"
#include "itemsQueue.h"

// We recommend using the global logger.
extern Logger logger;

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

    Event::PlayerOpenContainerEvent::subscribe([](const Event::PlayerOpenContainerEvent& event) {
        Container* player_container = &(event.mPlayer->getInventory());
        Container* block_container = event.mContainer;
        ItemsQueue blockItemsQueue(block_container);
        blockItemsQueue.sort();
        ItemsQueue playerItemsQueue(player_container,9);
        playerItemsQueue.sort();
        return true;
    });

    Event::PlayerOpenInventoryEvent::subscribe([](const Event::PlayerOpenInventoryEvent& event) {
        Container* player_container = &(event.mPlayer->getInventory());
        ItemsQueue itemsQueue(player_container,9);
        itemsQueue.sort();
        return true;
    });
}
