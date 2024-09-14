#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>


// Event handler class for managing custom events
class EventHandler {
  public:
    using EventCallback = std::function<void(void *)>;

    // Delete copy constructor and assignment operator to prevent multiple instances
    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;

    // Static method to access the singleton instance
    static EventHandler& getInstance() {
        static EventHandler instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    // Subscribe to an event with a callback
    void subscribe(const std::string& eventType, const EventCallback& callback) {
        eventListeners[eventType].push_back(callback);
    }

    // Emit an event, invoking all subscribers for that event
    void emit(const std::string& eventType, void *args) {
        if (eventListeners.find(eventType) != eventListeners.end()) {
            for (const auto& callback : eventListeners[eventType]) {
                callback(args);
            }
        } else {
            std::cout << "No listeners for event: " << eventType << std::endl;
        }
    }

  private:
    // Private constructor to enforce singleton usage
    EventHandler() = default;

    // Mapping from event type to a list of listeners (callbacks)
    std::unordered_map<std::string, std::vector<EventCallback>> eventListeners;
};

/*
 * notes:
 * scene manager will subscribe to change scene requests
 * change scene requests will include the enum of the scene to change as an input
 *
 */