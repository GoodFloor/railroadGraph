# Railroad cargo analyzer

## Input format

- The first line contains two integers: `S` and `T` - the number of stations and tracks
- The next `S` lines each contain three integers: `s`, `c_unload` and `c_load`, where
  - `s` - the id of a station
  - `c_unload` - the kind of goods unloaded at station `s`
  - `c_load` - the kind of goods loaded at station `s`
- The next `T` lines each contain two integers: `s_from` and `s_to` indicating a directed treack from station `s_from` to station `s_to`
- The last line contains an integer `s_0`, the starting station

## Launching

Launching this program requires one argument: file location for the input data. The program does not check if the provided data is valid.
