// In your program, move it to a separate file ClientHandler.java, and change the name
class Sleeper extends Thread {
	private String name;
	private int time;

	Sleeper(String name, int time) {
		this.name = name;
		this.time = time;
	}

	public void run() {
		System.out.println("zzz at " + name);
		try {
			Thread.sleep(time * 1000); // Times 1000 because it's in miliseconds
		}
		catch (InterruptedException exception) {
			// The operating system woke us up for no reason. Never mind, just wake up...
		}
		System.out.println("wakeup at " + name);
	}
}

public class ThreadTester {
	public static void main(String[] args) {
		Sleeper thread1 = new Sleeper("java_threadA", 5);
		Sleeper thread2 = new Sleeper("java_threadB", 2);
		thread1.start();
		thread2.start();
	}
}