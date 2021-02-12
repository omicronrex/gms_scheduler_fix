Thread scheduler resolution fix for GM:Studio and GM8.1

This hack works by providing a fake dll stub that sets the thread scheduler resolution to 1ms, providing a smooth framerate across studio and 8.1 games. The games are not hooked or patched, so it's possible to use with steam and it should also be fine for speedrunning communities.

# Affected versions
- Game Maker 8.1: all versions.
- GameMaker:Studio: all versions.
- GameMaker:Studio 2: all versions before and not including 2.3.2, which provides an api for modifying the scheduler resolution and a more sensible default.

# For developers
If you're making a game using 8.1 or studio 1.4 rather than patching an existing game, consider using [gmsched](https://github.com/skyfloogle/gmsched) instead, as it's a much cleaner solution.

# How to use
Simply download DBGHELP.DLL and place it next to the game maker 8 game or the studio runner. Remember that some studio games are packed, so use a tool like 7z to unpack them (you should be able to see the game .exe, data.win and some miscellaneous data files). If a studio game is still packed it won't work.

# What is scheduler resolution?
By default, in modern Windows, the thread scheduler resolution is 10 or even ~15.4ms. This means, if a thread tries to sleep or time something, it'll get invoked in the next possible interval. A coarse resolution means threads sleep very imprecisely, leading to massive frame drops in game maker games as they fail to present frames on time. By setting a finer resolution like 1ms, we make sure the game thread is woken up on time to present every frame.

# What's the catch?
The dll we're using as a hook isn't important for the games to run, so not much really. There are concerns about more power usage by the scheduler running more often, but since we're talking about games, it wouldn't really make much of a difference in the first place since this is expected anyway.

Moreover, this tool does not help with 8.0 games or issues related to the infamous gm8.x "joystick bug", or large memory allocation issues. If you still have problems with 8.0 and 8.1, consider patching them with [gm8x_fix](https://github.com/skyfloogle/gm8x_fix) version 0.3 or newer, as that fixes both the scheduler and the other issues mentioned.
