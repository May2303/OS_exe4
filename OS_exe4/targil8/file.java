import java.util.concurrent.locks.ReentrantLock;

/**
 * Abstract singleton class providing a base for creating singleton instances.
 * Uses a ReentrantLock for thread-safe initialization.
 */
abstract class Singleton {
    /** The single instance of the class. */
    private static Singleton instance;

    /** A reentrant lock for thread-safe initialization. */
    private static final ReentrantLock lock = new ReentrantLock();

    /** Protected constructor to prevent direct instantiation. */
    protected Singleton() {}

    /**
     * Gets the single instance of the class.
     *
     * @return The single instance of the class.
     */
    public static Singleton getInstance() {
        // Check if the instance is already created
        if (instance == null) {
            // Acquire the lock to ensure thread safety
            lock.lock();
            try {
                // Double-check to prevent unnecessary object creation
                if (instance == null) {
                    // Create the instance
                    instance = createInstance();
                }
            } finally {
                // Release the lock unconditionally
                lock.unlock();
            }
        }
        return instance;
    }

    /**
     * Abstract method to create the actual instance.
     *
     * @return The created instance.
     */
    protected abstract Singleton createInstance();
}

/**
 * A guard class to manage lock acquisition and release.
 */
class Guard {
    /** The lock to be managed. */
    private final ReentrantLock lock;

    /**
     * Constructs a guard with the specified lock.
     * Acquires the lock immediately.
     *
     * @param lock The lock to be managed.
     */
    public Guard(ReentrantLock lock) {
        this.lock.lock();
    }

    /**
     * Releases the acquired lock.
     */
    public void release() {
        lock.unlock();
    }
}