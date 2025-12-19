# MagicCard-Game-System
This project is a C++ card game system that simulates a multiplayer game based on colored and numbered cards. The system manages players, card hands, a draw pile, and a discard pile, while enforcing game rules that determine valid moves.

Players are identified by unique IDs and usernames, and the system supports dynamically adding and removing players. Each player holds a hand of cards, and all card data is managed using dynamically allocated arrays, ensuring efficient memory usage without relying on fixed-size containers or standard library data structures.

The game includes a draw pile from which players draw cards and a discard pile that tracks played cards. A card can be played only if it matches the color or number of the top card in the discard pile; otherwise, the player must draw a new card. Cards are represented using a compact format (e.g., R5, G10), and all piles preserve order.

Key gameplay features include:

Drawing cards from arbitrary positions in the draw pile

Switching hands between players

Playing cards with rule validation

Automatic game termination when a player runs out of cards or the draw pile becomes empty

The system provides detailed console output for every operation, handling invalid actions with clear warning messages. All memory is carefully managed to avoid leaks, and the design follows object-oriented principles with a clear separation between interface (.h) and implementation (.cpp).

This project demonstrates dynamic memory management, array resizing, game state management, rule-based logic, and robust error handling in C++.
