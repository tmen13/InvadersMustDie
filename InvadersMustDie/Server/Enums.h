#pragma once

typedef enum { standy_by, creation, association, start, ongoing, over } game_state;
typedef enum { linear, random, frozen } movement_type;
typedef enum { basic, dodger, boss } invader_type;
typedef enum { shield, ice, battery, enemy_boost, life, alchool, noclip } powerup_type;
typedef enum { common, uncommon, rare } occurrence_type;
typedef enum { temporary, permanent } powerup_duration_type;

char const *game_state_string[] = { "Stand By","Creation","Association", "Start", "On Going", "Game Over" };
char const *movement_type_string[] = { "Linear","Random","Frozen" };
char const *invader_type_string[] = { "Basic","Dodger","Boss" };
char const *powerup_type_string[] = { "Shield","Ice","Battery", "Enemy Boost", "Life", "Alchool", "No Clip" };
char const *occurrence_type_string[] = { "Common","Uncommon","Rare" };
char const *powerup_duration_type_string[] = { "Temporary","Permanent"};
