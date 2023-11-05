# Clock Class Documentation

The `Clock` class is a utility for managing multiple high-resolution timers within an application. Each timer can be individually started, measured, and manipulated in terms of its elapsed time.

## Public Methods

### `Clock()`

- **Description:** Constructor that initializes the `Clock` instance.

### `std::size_t create(bool deferStart = false)`

- **Description:** Creates a new timer. This timer is added to a collection of timers and can be referenced using the returned index value.
- **Parameters:**
    - `deferStart`: A boolean indicating whether to start the timer immediately upon creation. If `true`, the timer starts in a deferred state.
- **Returns:** A `std::size_t` that serves as an identifier for the newly created timer.

### `std::size_t elapsedMillisecondsSince(std::size_t id)`

- **Description:** Calculates the elapsed time in milliseconds since the specified timer was started.
- **Parameters:**
    - `id`: A `std::size_t` identifier for the timer whose elapsed time is to be calculated.
- **Returns:** The elapsed time in milliseconds as a `std::size_t`. Returns -1 if the timer has not been started.

### `std::size_t elapsedSecondsSince(std::size_t id)`

- **Description:** Calculates the elapsed time in seconds since the specified timer was started.
- **Parameters:**
    - `id`: A `std::size_t` identifier for the timer whose elapsed time is to be calculated.
- **Returns:** The elapsed time in seconds as a `std::size_t`. Returns -1 if the timer has not been started.

### `std::size_t elapsedNanosecondsSince(std::size_t id)`

- **Description:** Calculates the elapsed time in nanoseconds since the specified timer was started.
- **Parameters:**
    - `id`: A `std::size_t` identifier for the timer whose elapsed time is to be calculated.
- **Returns:** The elapsed time in nanoseconds as a `std::size_t`. Returns -1 if the timer has not been started.

### `void decreaseSeconds(std::size_t id, std::size_t seconds)`

- **Description:** Decreases the elapsed time of the specified timer by a given number of seconds.
- **Parameters:**
    - `id`: A `std::size_t` identifier for the timer to be manipulated.
    - `seconds`: The number of seconds to subtract from the timer's current elapsed time.

### `void decreaseMilliseconds(std::size_t id, std::size_t milliseconds)`

- **Description:** Decreases the elapsed time of the specified timer by a given number of milliseconds.
- **Parameters:**
    - `id`: A `std::size_t` identifier for the timer to be manipulated.
    - `milliseconds`: The number of milliseconds to subtract from the timer's current elapsed time.

### `void decreaseNanoseconds(std::size_t id, std::size_t nanoseconds)`

- **Description:** Decreases the elapsed time of the specified timer by a given number of nanoseconds.
- **Parameters:**
    - `id`: A `std::size_t` identifier for the timer to be manipulated.
    - `nanoseconds`: The number of nanoseconds to subtract from the timer's current elapsed time.

### `void restart(std::size_t id)`

- **Description:** Restarts the specified timer. The elapsed time is reset to the current time.
- **Parameters:**
    - `id`: A `std::size_t` identifier for the timer to be restarted.

## Private Members

### `std::vector<std::optional<std::chrono::high_resolution_clock::time_point>> _clocks`

- **Description:** A collection of optional time points representing the start times of the timers. An `std::nullopt` value indicates a timer that has been created but not started or has been invalidated.

---

This documentation provides a comprehensive guide to the methods available in the `Clock` class for creating and managing timers. It is important to manage the indices returned by the `create` method as they are needed to reference the specific timers for all subsequent operations.