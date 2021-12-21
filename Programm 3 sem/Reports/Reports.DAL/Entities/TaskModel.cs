using System;

namespace Reports.DAL.Entities
{
    public class TaskModel
    {
        public Guid Id { get; private set; }
        public string Title { set; get; }
        public string Context { set; get; }
        public DateTime CreatedOn { set; get; }
        public DateTime LastUpdateOn { set; get; }
        public Guid AssignedEmployeeId { set; get; }
        public TaskStatus TaskStatus { set; get; }
        private TaskModel()
        {
        }
        public TaskModel(string title, string context, Guid assignedEmployeeId)
        {
            Id = new Guid();
            Title = title;
            Context = context;
            AssignedEmployeeId = assignedEmployeeId;
            CreatedOn = DateTime.Now;
            LastUpdateOn = DateTime.Now;
            TaskStatus = TaskStatus.Open;
        }
    }
    public class RequestTaskModel
    {
        public string Title { get; }
        public string Context { get; }
        public Guid AssignedEmployeeId { get; }
    }
    public class RequestTaskUpdateModel
    {
        public Guid Id { get; }
        public string Title { get; }
        public string Context { get; }
        public Guid AssignedEmployeeId { get; }
        public TaskStatus TaskStatus { get; }
    }
}