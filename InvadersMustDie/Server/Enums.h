#pragma once

typedef enum { standy_by, creation, association, start, ongoing, over } game_state;
typedef enum { linear, random } movement_type;
typedef enum { basic, dodger, boss } invasor_type;
typedef enum { shield, ice, battery, enemy_boost, life, alchool, noclip } powerup_type;
typedef enum { common, uncommon, rare } occurrence_type;
typedef enum { temporary, permanent } powerup_duration_type;